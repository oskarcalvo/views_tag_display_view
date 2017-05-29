<?php


class views_tag_display_view_plugin_display_code extends views_plugin_display_extender {

  /**
   * Provide the form to set new option.
   */
  function options_form(&$form, &$form_state) {
    switch ($form_state['section']) {
      case 'views_tag_display_view':
        $form['#title'] .= t('Example setting');
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
        $empty = trim($new_option);
        $empty = empty($empty);
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
    if ($new_option) {
      $new_option = t('Yes');
    }
    else {
      $new_option = t('None');
    }
    $options['views_tag_display_view'] = array(
      'category' => 'other',
      'title'    => t('Tag for display view'),
      'value'    => $new_option,
      'desc'     => t('Add some option.'),
    );
  }

}