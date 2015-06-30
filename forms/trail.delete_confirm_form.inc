<?php

/**
 * @file
 * Contains trail delete confirm form.
 */

/**
 * trail delete confirmation form.
 */
function trail_delete_confirm_form($form, &$form_state) {
  $trail = $form_state['trail'];
  return confirm_form(
    $form, t('Are you sure you want to delete trail "%title"', array('%title' => entity_label('trail', $trail))), 'admin/content/trail', t('Activation data and log assigned to this trail will also be deleted. This action cannot be undone.')
  );
}

/**
 * trail delete confirmation form submit callback.
 */
function trail_delete_confirm_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $trail = $form_state['trail'];

    // Title is not available after deletion.
    $title = entity_label('trail', $trail);
    $return = $trail->delete();
    if ($return !== FALSE) {
      drupal_set_message(t('trail %title has been deleted.', array('%title' => $title)));

      $form_state['redirect'] = 'admin/content/trails';
    }
    else {
      drupal_set_message(t('There was an error during deleting trail from the database. If the issue persists, please contact the site administrator'), 'error');
    }
  }
}
