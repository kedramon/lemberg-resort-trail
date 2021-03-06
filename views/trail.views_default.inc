<?php

/**
 * Implements hook_views_default_views().
 */
function trail_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'trail') . '/views', '/\.view$/');
  foreach ($files as $path => $file) {
    require $path;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
