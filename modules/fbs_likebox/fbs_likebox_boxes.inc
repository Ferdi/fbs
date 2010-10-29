<?php

class fbs_likebox_box extends fbs_boxes_default {
  
  public $fb_plugin_name;

  protected function __construct(){
    parent::__construct();
    $this->fb_plugin_name = 'like-box';
  }

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults(){
    $info = fbs_likebox_fbs_plugins_info();
    return $info['like']['defaults'];
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    $info = fbs_likebox_fbs_plugins_info();
    $form = $info['like']['options_form'];
    
    foreach ( $form as $key => &$el ) {
      $el['#default_value'] = $this->options[$key];
    }
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render(){
    $block = parent::render();
    $block['content'] = theme('fbs_box', $this);
    return $block;
  }
}