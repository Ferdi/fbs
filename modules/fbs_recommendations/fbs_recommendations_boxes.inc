<?php

class fbs_recommendations_box extends fbs_boxes_default {
  
  public $fb_plugin_name;

  protected function __construct(){
    parent::__construct();
    $this->fb_plugin_name = 'recommendations';
  }

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults(){
    return fbs_attrs_defaults('recommendations');
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    $form = fbs_attrs_form('recommendations');
    
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