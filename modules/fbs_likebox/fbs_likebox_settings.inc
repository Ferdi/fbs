<?php

//$Id$

function _fbs_likebox_fb_defaults(){
  return array(
    'href' => '', 
    'width' => 292, 
    'height' => '', 
    'connections' => 10, 
    'stream' => 1, 
    'header' => 1 
  );
}

function _fbs_likebox_fb_options_form(){
  $form = array();
  
  $form['href'] = array(
    '#type' => 'textfield', 
    '#title' => t('Facebook Page URL'), 
    '#description' => t('The URL of the Facebook Page for this Like box.') 
  );
  
  $form['width'] = array(
    '#type' => 'textfield', 
    '#title' => t('Width'), 
    '#description' => t('The width of the wiget in pixel') 
  );
  
  $form['height'] = array(
    '#type' => 'textfield', 
    '#title' => t('Height'), 
    '#description' => t('The height of the wiget in pixel') 
  );
  
  $form['connections'] = array(
    '#type' => 'textfield', 
    '#title' => t('Connections'), 
    '#description' => t('Show a sample of this many users who have liked this page ') 
  );
  
  $form['stream'] = array(
    '#type' => 'radios', 
    '#title' => 'Show stream', 
    '#description' => t('Show the profile stream for the public profile'), 
    '#options' => array(
      t('False'), 
      t('True') 
    ) 
  );
  
  $form['header'] = array(
    '#type' => 'radios', 
    '#title' => t('Show header'), 
    '#description' => t('Show the "find us on facebook" bar at the top. Only shown when either stream or connections are present'), 
    '#options' => array(
      t('False'), 
      t('True') 
    ) 
  );
  
  return $form;
}

function _fbs_likebox_d_settings_form(){
  $form = array();
  $form['node_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['node_types']['fb_social_like_node_types'] = array(
    '#type' => 'checkboxes',
    '#description' => t('Select types that will use the facebook like plugin'),
    '#default_value' => array(),
    '#options' => node_get_types('names'),
  );
  
  $form['fb_social_like_opengraph_tags'] = array(
    '#type' => 'checkbox',
    '#title' => t('Output the facebook opengraph tags for the above content types'),
    '#description' => t('This module has limited support for fb opengraph tags. Uncheck if you are using some other modules that better support opengraph protocol'),
    '#default_value' =>  1,
  );
  
  $form['widget_location'] = array(
    '#type' => 'fieldset',
    '#title' => t('Widget location and display'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['widget_location']['fb_social_like_location'] = array(
    '#type' => 'radios',
    '#title' => t('widget location'),
    '#default_value' =>  0,
    '#options' => array(t('Node links'), t('Node content')),
    '#description' => t('The widget can be printed in the "links" are of the node or as part of the node content'),
  );
  
  $form['widget_location']['fb_social_like_display_teasers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show on teasers'),
    '#default_value' =>  1,
    '#description' => t('Should the widget be displayed on teasers?'),
  );
  return $form;
}



