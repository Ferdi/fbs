<?php

//$Id$

// keep the default separate as they are used by boxes and presets

function _fbs_like_fb_defaults(){
  return array(
      'layout' => 'button_count', 
      'show_faces' => 0, 
      'width' => 350, 
      'action' => 'like', 
      'font' => 'verdana', 
      'colorscheme' => 'dark' 
  );
}

function _fbs_like_fb_options_form(){
  $form = array();
  $form['layout'] = array(
      '#type' => 'select', 
      '#title' => t('Layout style'), 
      '#description' => t('Determines the size and the amount of the social context next to the button'), 
      '#options' => array(
          'standard' => t('standard'), 
          'button_count' => t('button_count'), 
          'box_count' => t('box_count') 
      )
  );
  
  $form['show_faces'] = array(
      '#type' => 'checkbox', 
      '#title' => t('Show faces'), 
      '#description' => t('Show profiles pictures below the button') 
  );
  
  $form['width'] = array(
      '#type' => 'textfield', 
      '#title' => t('Width'), 
      '#description' => t('The width of the plugin in pixel') 
  );
  
  $form['action'] = array(
      '#type' => 'select', 
      '#title' => t('Verb'), 
      '#description' => t('The verb to display in the button'), 
      '#options' => array(
          'like' => t('like'), 
          'recommend' => t('recommend') 
      ) 
  );
  
  $form['font'] = array(
      '#type' => 'select', 
      '#title' => t('Font'), 
      '#description' => t('The font of the plugin'), 
      '#options' => array(
          'arial' => t('arial'), 
          'verdana' => t('verdana') 
      ) 
  );
  
  $form['colorscheme'] = array(
      '#type' => 'select', 
      '#title' => t('Color'), 
      '#description' => t('The color scheme of the plugin'), 
      '#options' => array(
          'dark' => t('dark'), 
          'light' => t('light'), 
          'evil' => t('evil') 
      ) 
  );
  
  return $form;
}

function _fbs_like_d_settings_form($settings){

  $form = array();
  $form['node_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['node_types']['types'] = array(
    '#type' => 'checkboxes',
    '#description' => t('Select types that will use the facebook like plugin'),
    '#default_value' =>  isset($settings['node_types']['types']) ? array_keys(array_filter($settings['node_types']['types'])): array(),
    '#options' => node_get_types('names'),
  );
  
  $form['opengraph_tags'] = array(
    '#type' => 'checkbox',
    '#title' => t('Output the facebook opengraph tags for the above content types'),
    '#description' => t('This module has limited support for fb opengraph tags. Uncheck if you are using some other modules that better support opengraph protocol'),
    '#default_value' =>  isset($settings['opengraph_tags']) ? $settings['opengraph_tags']: 1,
  );
  
  $form['widget_location'] = array(
    '#type' => 'fieldset',
    '#title' => t('Widget location and display'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['widget_location']['location'] = array(
    '#type' => 'radios',
    '#title' => t('widget location'),
    '#default_value' =>  isset($settings['widget_location']['location']) ? $settings['widget_location']['location']: 0,
    '#options' => array(t('Node links'), t('Node content')),
    '#description' => t('The widget can be printed in the "links" are of the node or as part of the node content'),
  );
  
  $form['widget_location']['display_teasers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show on teasers'),
    '#default_value' =>  isset($settings['widget_location']['display_teasers']) ? $settings['widget_location']['display_teasers']: 1,
    '#description' => t('Should the widget be displayed on teasers?'),
  );
  return $form;
}


