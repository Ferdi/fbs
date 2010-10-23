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
    'title plural proper' => t('Widgets'), 
);

function fbs_ctools_export_ui_form(&$form, &$form_state){
  dpm($form_state);
  ctools_include('dependent');
  $export = $form_state['item'];
  
  $form['description'] = array(
      '#title' => t('description'), 
      '#type' => 'textfield', 
      '#default_value' => ! empty($export->description) ? $export->description : '', 
      '#description' => t('Description for this preset.') 
  );
  
  $form['widget_type'] = array(
      '#title' => t('type'), 
      '#type' => 'radios', 
      '#options' => array(
          'likebox' => 'like box', 
          'commentbox' => 'comment box' 
      ), 
      '#default_value' => ! empty($export->widget_type) ? $export->widget_type : 'likebox', 
      '#description' => t('Description for this preset.') 
  );
  
  module_load_include('inc', 'fbs', '/includes/fbs_widgets_settings');
  $form['fb_settings'] = array(
      '#type' => 'fieldset', 
      '#title' => t('Facebook widget settings'), 
      '#tree' => TRUE 
  );
  $fb_settings = fbs_fb_settings_like();
  foreach ( $fb_settings as $k => &$s ) {
    $s['#default_value'] = ! empty($export->fb_settings[$k]) ? $export->fb_settings[$k] : $s['#default_value'];
    $form['fb_settings'][$k] = $s;
  }
  
  // drupal settings
  $form['d_settings'] = array(
      '#type' => 'fieldset', 
      '#title' => t('Drupal settings'), 
      '#tree' => TRUE 
  );
  
  $d_settings = fbs_d_settings_like();

  foreach ( $d_settings as $k => &$s ) {
  	if (isset($s['#default_value'])){
    $s['#default_value'] = ! empty($export->d_settings[$k]) ? $export->d_settings[$k] : $s['#default_value'];
  	}
    $form['d_settings'][$k] = $s;
  }
}

/*
  dpm($form);
 */

  /*
  $form['fb_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook widget settings'), 
      '#process' => array(
          'ctools_dependent_process' 
      ), 
      '#dependency' => array(
          'radio:widget_type' => array(
              'likebox' 
          ) 
      ),
      '#tree' => TRUE,
  );
  */
  
  
  /*
  $form['fb_settings']['widget_type'] = array(
      '#title' => t('type'), 
      '#type' => 'radios', 
      '#options' => array(
          'likebox' => 'like box', 
          'commentbox' => 'comment box' 
      ), 
      '#default_value' => ! empty($export->widget_type) ? $export->widget_type : 'likebox', 
      '#description' => t('Description for this preset.') 
  );

  $form['fb_settings']['title'] = array(
      '#title' => t('Title'), 
      '#type' => 'textfield', 
      '#default_value' => '', 
      '#description' => t('If set to normal or tab, enter the text to use for the menu item.'), 
      '#process' => array(
          'ctools_dependent_process' 
      ), 
      '#dependency' => array(
          'radio:widget_type' => array(
              'likebox' 
          ) 
      ),
       '#default_value' => ! empty($export->settings['title']) ? $export-> settings['title'] : 'likebox', 
  );
    */
