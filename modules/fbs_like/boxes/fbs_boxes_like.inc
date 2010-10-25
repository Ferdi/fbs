<?php

class fbs_like_boxes_like extends fbs_boxes_default {
	
  public $fb_plugin_name;

  protected function __construct() {
    parent::__construct();
    $this -> fb_plugin_name = 'like';
  }
  
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return fbs_like_like_defaults();
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
  	 $form = fbs_like_like_options_form();
  	 foreach($form as $key => &$el){
  	   $el['#default_value'] = $this -> options[$key];
  	 }
     return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $block = parent::render();
    $block['content'] = theme_fbs_boxes_box($this);
    return $block;
  }
}