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
  $form_state['item']->fb_settings = $form_state['values']['fb_settings_' . $type];
  $form_state['item']->d_settings = $form_state['values']['d_settings_' . $type];
}

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
      '#description' => t('Description for this preset.'), 

  );
  
  // output all form settings here but show/hide using
  // ctools 'dependent' plugin
  
  foreach ( $all_widgets as $type => $widget ) {
  	
  	// fb settings
    $id = 'fbs-settings-' . $type;
    $wrapper_id = $id . '-wrapper';
    $form['fb_settings_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => t('%description  - Facebook settings', array('%description' => $widget['description'])), 
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
        
        '#tree' => TRUE,
    );
    
    foreach ( $widget['options_form'] as $k => $v ) {
      $form['fb_settings_' . $type][$k] = $v;
      $form['fb_settings_' . $type][$k]['#default_value'] = ! empty($export->fb_settings[$k]) ? $export->fb_settings[$k] : $widget['defaults'][$k];
    }
    
    // drupal settings
      $id = 'fbs-d-settings-' . $type;
    $wrapper_id = $id . '-wrapper';
    $form['d_settings_' . $type] = array(
        '#type' => 'fieldset', 
        '#title' => t('%description  - Drupal settings', array('%description' => $widget['description'])), 
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
        
        '#tree' => TRUE,
    );
    
    foreach ( $widget['settings_form'] as $k => $v ) {
    	//dpm($k);
    	//dpm($v);
      $form['d_settings_' . $type][$k] = $v;
      if (! empty($export->d_settings[$k]))
      $form['d_settings_' . $type][$k]['#default_value'] =  $export->d_settings[$k];
    }  
  
  }
}

