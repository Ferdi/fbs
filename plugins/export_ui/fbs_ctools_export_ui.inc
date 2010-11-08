<?php

// $Id$
$plugin = array(
    'schema' => 'fbs_presets', 
    'menu' => array(
        'menu item' => 'fbs_presets' 
    ), 
    'title' => t('Facebook social plugins'), 
    
    'title singular' => t('widget'), 
    'title plural' => t('widgets'), 
    'title singular proper' => t('Widget'), 
    'title plural proper' => t('Widgets') 
);

/**
 * submit handler
 */
function fbs_ctools_export_ui_form_submit(&$form, &$form_state){
  $type = $form_state['values']['plugin_type']['widget_type'];
  $form_state['item']->widget_type = $type;
  $form_state['item']->fb_settings = $form_state['values']['fbs_settings_' . $type]['fb_settings_' . $type];
  $form_state['item']->d_settings = $form_state['values']['fbs_settings_' . $type]['d_settings_' . $type];
}

function fbs_ctools_export_ui_form(&$form, &$form_state){
  
  ctools_include('dependent');
  $export = $form_state['item'];

  $form['description'] = array(
      '#title' => t('description'), 
      '#type' => 'textfield', 
      '#default_value' => ! empty($export->description) ? $export->description : '', 
      '#description' => t('Description for this preset.') 
  );
  
  $all_widgets = module_invoke_all('fbs_plugins_info');
  $options = array();
  foreach ( $all_widgets as $widget ) {
    $options[$widget['name']] = $widget['description'];
  }
  
  $form['plugin_type'] = array(
      '#type' => 'fieldset', 
      '#title' => t('Facebook plugin type'), 
      '#tree' => TRUE 
  );
  
  $form['plugin_type']['widget_type'] = array(
      '#title' => t('type'), 
      '#type' => 'radios', 
      '#options' => $options, 
      '#default_value' => ! empty($export->widget_type) ? $export->widget_type : 'like', 
      '#description' => t('Description for this preset.') 
  );
  
  // output all form settings here but show/hide using
  // ctools 'dependent' plugin
  

  foreach ( $all_widgets as $type => $widget ) {
    
    // fb settings
    $id = 'fbs-settings-' . $type;
    $wrapper_id = $id . '-wrapper';
    $form['fbs_settings_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => t('%description  - settings', array(
            '%description' => $widget['description'] 
        )), 
        '#input' => TRUE, 
        '#process' => array(
            'ctools_dependent_process' 
        ), 
        '#dependency' => array(
            'radio:plugin_type[widget_type]' => array(
                $type 
            ) 
        ), 
        '#id' => $id, 
        '#prefix' => '<div id="' . $wrapper_id . '">', 
        '#suffix' => '</div>', 
        
        '#tree' => TRUE 
    );
    
    // facebook settings
    
    $form['fbs_settings_' . $type]['fb_settings_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => 'Facebook settings (options)', 
    );
    
    foreach ( $widget['options_form'] as $k => $v ) {
      $form['fbs_settings_' . $type]['fb_settings_' . $type][$k] = $v;
      $form['fbs_settings_' . $type]['fb_settings_' . $type][$k]['#default_value'] = ! empty($export->fb_settings[$k]) ? $export->fb_settings[$k] : $widget['defaults'][$k];
    }
    
    // drupal settings
    
    $form['fbs_settings_' . $type]['d_settings_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => 'Drupal settings' 
    );
    
    $func = 'fbs_'. $type . '_d_settings_form';
    if (function_exists($func)){
    $fb_settings_form = call_user_func($func, $export->d_settings);
    
    foreach ( $fb_settings_form as $k => $v ) {
      $form['fbs_settings_' . $type]['d_settings_' . $type][$k] = $v;
    }
    }
    


  }
}

