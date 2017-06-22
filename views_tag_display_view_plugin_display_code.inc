<?php

/**
 * Created by PhpStorm.
 * User: oskar
 * Date: 26/05/17
 * Time: 13:11
 */
class views_tag_display_view_plugin_display_code extends views_plugin_display_extender {

  function init(&$view, &$display) {
    parent::init($view, $display);
  }

  /**
   * Static member function to list which sections are defaultable
   * and what items each section contains.
   */
  function defaultable_sections(&$sections, $section = NULL) {

    $new_sections= ['views_tag_display_view' => ['views_tag_display_view']];
    $sections = $sections + $new_sections;

    foreach ($this->extender as $extender) {
      $extender->defaultable_sections($sections, $section);
    }

    if ($section) {
      if (!empty($sections[$section])) {
        return $sections[$section];
      }
    }
    else {
      return $sections;
    }
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  function options_definition_alter(&$options) {
	  
    parent::options_definition_alter($options);
    
    $options['defaults']['default']['views_tag_display_view'] = TRUE;
    $options['views_tag_display_view'] = [
      'default' => '',
      'translatable' => FALSE,
    ];

    return $options;
  }

  /**
   * Provide the form to set new option.
   */
  function options_form(&$form, &$form_state) {

    switch ($form_state['section']) {
      case 'views_tag_display_view':
        $form['#title'] .= t('Display views tags');
        $form['views_tag_display_view'] = array(
          '#type' => 'textfield',
          '#description' => t('Add tags to describe this display views'),
          '#default_value' => $this->display->get_option('views_tag_display_view'),
        );
        break;
    }
  }

  /**
   * Inserts the code into the view display.
   */
  function options_submit(&$form, &$form_state) {
	  
    $new_option  = $form_state['values']['views_tag_display_view'];
    
    switch ($form_state['section']) {
      case 'views_tag_display_view':
        $this->display->set_option('views_tag_display_view', $new_option);
        break;
    }
  }


  /**
   * Summarizes new option.
   *
   * Lists the fields as either 'Yes' if there is text or 'None' otherwise and
   * categorizes the fields under the 'Other' category.
   */
  function options_summary(&$categories, &$options) {
 
    $new_option = check_plain(trim($this->display->get_option('views_tag_display_view')));
     $options['views_tag_display_view'] = array(
      'category' => 'other',
      'title'    => t('Tag for views'),
      'value'    => isset($new_option) ? t('Yes') : t('No'),
      'desc'     => t('Add some option.'),
    );
  }

}
