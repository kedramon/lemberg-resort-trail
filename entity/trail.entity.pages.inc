<?php

/**
 * @file
 * trail entity pages.
 */

/**
 * Menu callback. Returns trail add/edit form.
 */
function trail_add_page(trail $trail = NULL) {
  $trail = !empty($trail) ? $trail : trail_create();

  $title = empty($trail->tid) ? t('Add new trail') : t('Edit trail %title', array('%title' => entity_label('trail', $trail)));
  drupal_set_title($title, PASS_THROUGH);

  module_load_include('inc', 'trail', 'forms/trail.entity_form');
  $form_state = array(
    'trail' => $trail,
  );
  return drupal_build_form('trail_edit_form', $form_state);
}

/**
 * Menu callback. Returns trail delete confirmation form.
 */
function trail_delete_page(trail $trail) {
  module_load_include('inc', 'trail', 'forms/trail.delete_confirm_form');
  $form_state = array(
    'trail' => $trail,
  );
  return drupal_build_form('trail_delete_confirm_form', $form_state);
}

/**
 * Menu callback. Returns trail view page.
 */
function trail_view_page(trail $trail, $view_mode = 'landing') {
  if ($view_mode === 'output') {
    $entity_uri = entity_uri('trail', $trail);
    drupal_goto($entity_uri['path']);
  }

  return $trail->view($view_mode, NULL, TRUE);
}
