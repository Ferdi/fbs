<?php

function fbs_definition_facepile_defaults(){
  return array(
      'max-rows' => 1, 
      'width' => 200 
  );
}

function fbs_definition_facepile_options_form(){
  $form = array();
  
  $form['num-rows'] = array(
      '#type' => 'textfield', 
      '#title' => t('Width'), 
      '#description' => t('The width of the plugin in pixel') 
  );
  $form['width'] = array(
      '#type' => 'textfield', 
      '#title' => t('Width'), 
      '#description' => t('The width of the plugin in pixel') 
  );
  
  return $form;
}
