<?php

// $Id$
$plugin = array(
    'schema' => 'fbs_preset', 
    'menu' => array(
        'menu item' => 'fbs_presets' 
    ), 
    'title' => t('Facebook social plugins'), 
    
    'title singular' => t('plugin'), 
    'title plural' => t('plugins'), 
    'title singular proper' => t('Plugin'), 
    'title plural proper' => t('Plugins') 
);

/**
 * submit handler
 */
function fbs_ctools_export_ui_form_submit(&$form, &$form_state){
  dpm($form_state);
  $type = $form_state['values']['fb_plugin_type']['plugin_type'];
  $form_state['item']->plugin_type = $type;
  $form_state['item']->fb_attrs = $form_state['values']['fbs_settings_' . $type]['fb_attrs_' . $type];
  $form_state['item']->settings = $form_state['values']['fbs_settings_' . $type]['settings_' . $type];
}

/**
 * The preset add/edit form
 */
function fbs_ctools_export_ui_form(&$form, &$form_state){
  
  ctools_include('dependent');
  $export = $form_state['item'];
  dpm($export);
  
  $form['description'] = array(
      '#title' => t('description'), 
      '#type' => 'textfield', 
      '#default_value' => ! empty($export->description) ? $export->description : '', 
      '#description' => t('Description for this preset.') 
  );
  
  $all_plugins = module_invoke_all('fbs_plugins_info');
  $options = array();
  foreach ( $all_plugins as $plugin ) {
    $options[$plugin['name']] = $plugin['description'];
  }
  
  $form['fb_plugin_type'] = array(
      '#type' => 'fieldset', 
      '#title' => t('Facebook plugin type'), 
      '#tree' => TRUE 
  );
  
  $form['fb_plugin_type']['plugin_type'] = array(
      '#title' => t('type'), 
      '#type' => 'radios', 
      '#options' => $options, 
      '#default_value' => ! empty($export->plugin_type) ? $export->plugin_type : 'like', 
      '#description' => t('Description for this preset.') 
  );
  
  // output all form settings here but show/hide using
  // ctools 'dependent' plugin
  
  foreach ( $all_plugins as $type => $plugin ) {
    
    // fb settings
    $id = 'fbs-settings-' . $type;
    $wrapper_id = $id . '-wrapper';
    $form['fbs_settings_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => t('%description  - settings', array(
            '%description' => $plugin['description'] 
        )), 
        '#input' => TRUE, 
        '#process' => array(
            'ctools_dependent_process' 
        ), 
        '#dependency' => array(
            'radio:fb_plugin_type[plugin_type]' => array(
                $type 
            ) 
        ), 
        '#id' => $id, 
        '#prefix' => '<div id="' . $wrapper_id . '">', 
        '#suffix' => '</div>', 
        
        '#tree' => TRUE 
    );
    
    // facebook attrs
    $form['fbs_settings_' . $type]['fb_attrs_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => 'Fb plugin attributes' 
    );
    
    $plugin['options_form'] = fbs_attrs_form($type); // rename options_form to attrs_form
    $plugin['defaults'] = fbs_attrs_defaults($type);
    
    foreach ( $plugin['options_form'] as $k => $v ) {
      $form['fbs_settings_' . $type]['fb_attrs_' . $type][$k] = $v;
      $form['fbs_settings_' . $type]['fb_attrs_' . $type][$k]['#default_value'] = ! empty($export->fb_attrs[$k]) ? $export->fb_attrs[$k] : $plugin['defaults'][$k];
    }
    
    // drupal settings
    $form['fbs_settings_' . $type]['settings_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => 'Drupal settings' 
    );
    
    $fb_attrs_form = fbs_settings_form($type, $export->settings);
    
    foreach ( $fb_attrs_form as $k => $v ) {
      $form['fbs_settings_' . $type]['settings_' . $type][$k] = $v;
    }
    
    $form['fbs_settings_' . $type]['settings_' . $type] += _fbs_ctools_export_ui_create_block_form($export);

  }
}

function _fbs_ctools_export_ui_create_block_form($export){
  $form = array();
  $form['block'] = array(
      '#type' => 'checkbox', 
      '#title' => t('Create a block'), 
      '#description' => t('Create a drupal block that contains this plugin.  You have to enable the block manually to show up.'), 
      
      '#default_value' => isset($export->settings['block']) ? $export->settings['block'] : 0 
  );
  return $form;
}

