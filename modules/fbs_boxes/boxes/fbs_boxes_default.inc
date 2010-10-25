<?php

abstract class fbs_boxes_default extends boxes_box {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $block['title'] = $title;
    $block['subject'] = $title;
    $block['delta'] = $this->delta;
    //$block['content'] = theme_fbs_box($this);
    return $block;
  }
}