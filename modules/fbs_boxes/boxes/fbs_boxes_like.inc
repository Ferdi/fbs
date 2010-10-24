<?php

class fbs_boxes_like extends fbs_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
  	fbs_include('fbs_definition_like');
    return fbs_definition_like_defaults();
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
  	 fbs_include('fbs_definition_like');
  	 $form = fbs_definition_like_options_form();
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
    $block['content'] = theme_fbs_box($this);
    return $block;
  }
}