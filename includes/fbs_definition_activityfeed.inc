<?php

function fbs_definition_like_defaults(){
  return array(
      'layout_style' => 'button_count', 
      'show_faces' => 0, 
      'width' => 350, 
      'verb' => 'like', 
      'font' => 'verdana', 
      'color' => 'dark' 
  );
}

function fbs_definition_like_options_form(){
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
  
  $form['verb'] = array(
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
  
  $form['color'] = array(
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
