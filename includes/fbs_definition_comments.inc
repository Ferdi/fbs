<?php

function fbs_definition_comments_defaults(){
  return array(
      'numposts' => 10, 
      'width' => 550, 
      'css' => '', 
      'simple' => 0, 
      'reverse' => 0, 
      'publish_feed' => 0, 
  );
}

function fbs_definition_comments_options_form(){
  $form = array();


  $form['numposts'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of posts'),
    '#description' => t('The maximum number of posts to display. You can set numposts to 0 to not display any comments. (Default value is 10.)'),
  );
  
  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('The width of the Comments Box in pixels. (Default value is 550px.)'),
  );
  
  $form['css'] = array(
    '#type' => 'textfield',
    '#title' => t('The URL to your own stylesheet.'),
    '#description' => t('Note: To provide you with better performance, we cache your stylesheet. If you update your stylesheet, you should use a cachebreaker in the URL to the stylesheet, typically by appending a version number to the .CSS file extension, as in http://www.example.com/my.css?2'),
  );
  
  $form['simple'] = array(
    '#type' => 'radios',
    '#title' => 'Simple',
    '#description' => t('When true, a rounded box does not appear around each post on your site. (Default value is false.)'),
    '#options' => array(t('False'), t('True')),
  );
  
  $form['reverse'] = array(
    '#type' => 'radios',
    '#title' => 'Reverse',
    '#description' => t('When true, reverses order of comments so the most recent one appears at the bottom of the list and the composer appears at the bottom of the page.'),
    '#options' => array(t('False'), t('True')),
  );
  
  $form['publish_feed'] = array(
    '#type' => 'radios',
    '#title' => 'Publish feed',
    '#description' => t('Indicates whether the Post comment to my Facebook profile check box is checked. If false, the user must check the check box before the comment can be published to a user\'s Feed'),
    '#options' => array(t('False'), t('True')),
  );

  return $form;
}

