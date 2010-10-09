<?php

function fbs_fb_settings_like(){
  $form = array();
  $form['layout_style'] = array(
    '#type' => 'select',
    '#title' => t('Layout style'),
    '#description' => t('Determines the size and the amount of the social context next to the button'),
    '#default_value' => 'button_count',
    '#options' => array('standard' => t('standard'), 'button_count' => t('button_count'), 'box_count' => t('box_count') ),
  );
  
  $form['show_faces'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show faces'),
    '#description' => t('Show profiles pictures below the button'),
    '#default_value' => 0,
  );
  
  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('The width of the plugin in pixel'),
    '#default_value' => 350,
  );
  
  $form['verb'] = array(
    '#type' => 'select',
    '#title' => t('Verb'),
    '#description' => t('The verb to display in the button'),
    '#default_value' => 'like',
    '#options' => array('like' => t('like'), 'recommend' => t('recommend') )
  );
  
  $form['font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#description' => t('The font of the plugin'),
    '#default_value' => 'verdana',
    '#options' => array('arial' => t('arial'), 'verdana' => t('verdana') )
  );
  
  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('Color'),
    '#description' => t('The color scheme of the plugin'),
    '#default_value' => 'dark',
    '#options' => array('dark' => t('dark'), 'light' => t('light'), 'evil' => t('evil') )
  );
  
  return $form;
}
