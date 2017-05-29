<?php

/**
 * Implements Hook_views_plugins().
 */
function views_tag_display_view_views_plugins() {
  $path = drupal_get_path('module', 'views_tag_display_view');
  $plugins = [];
  $plugins['display_extender']['views_tag_display_view'] = [
    'title' => t('display view tags'),
    'help' => t('Add tags to a display view'),
    'path' => $path,
    'handler' => '_views_tagdisplayview_plugin_display_code',
  ];
  return $plugins;
}