<?php

function fbs_definition_share_defaults(){
  return array(
      'layout_style' => 'button_count', 
  );
}

function fbs_definition_share_options_form(){
  $form = array();
  $form['layout_style'] = array(
      '#type' => 'select', 
      '#title' => t('Layout style'), 
      '#description' => t('Determines the size and the amount of the social context next to the button'), 
      '#options' => array(
          'standard' => t('standard'), 
          'button_count' => t('button_count'), 
          'box_count' => t('box_count') 
      ) 
  );
  
  return $form;
}
