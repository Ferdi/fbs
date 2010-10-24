<?php

function fbs_definition_likebox_defaults(){
  return array(
      'href' => '', 
      'width' => 292, 
      'height' => '', 
      'connections' => 10, 
      'stream' => 1, 
      'header' => 1 
  );
}

function fbs_definition_likebox_options_form(){

  $form = array();

  $form['href'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Page URL'),
    '#description' => t('The URL of the Facebook Page for this Like box.'),
  );
  
  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('The width of the wiget in pixel'),
  );
  
  $form['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('The height of the wiget in pixel'),
  );
  
  $form['connections'] = array(
    '#type' => 'textfield',
    '#title' => t('Connections'),
    '#description' => t('Show a sample of this many users who have liked this page '),
  );
  
  $form['stream'] = array(
    '#type' => 'radios',
    '#title' => 'Show stream',
    '#description' => t('Show the profile stream for the public profile'),
    '#options' => array(t('False'), t('True')),
  );
  
  $form['header'] = array(
    '#type' => 'radios',
    '#title' => t('Show header'),
    '#description' => t('Show the "find us on facebook" bar at the top. Only shown when either stream or connections are present'),
    '#options' => array(t('False'), t('True')),
  );
  
  return $form;
}

