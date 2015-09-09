<?php

/**
 * @file
 * Contains trail entity form.
 */

/**
 * trail entity edit form.
 */
function trail_edit_form($form, &$form_state) {
  $trail = $form_state['trail'];

  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Publishing options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'additional_settings',
    '#weight' => 95,
  );
  $form['options']['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published'),
    '#default_value' => $trail->status,
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  field_attach_form('trail', $trail, $form, $form_state);

  return $form;
}

/**
 * trail entity edit form validation callback.
 */
function trail_edit_form_validate($form, &$form_state) {
  $trail = $form_state['trail'];
  field_attach_form_validate('trail', $trail, $form, $form_state);
}

/**
 * trail entity edit form submit callback.
 */
function trail_edit_form_submit($form, &$form_state) {
  $trail = $form_state['trail'];
  form_state_values_clean($form_state);
  entity_form_submit_build_entity('trail', $trail, $form, $form_state);

  $return = $trail->save();
  if ($return) {
    if ($return == SAVED_NEW) {
      drupal_set_message(t('trail %title has been created.', array('%title' => entity_label('trail', $trail))));
    }
    else {
      drupal_set_message(t('trail %title has been updated.', array('%title' => entity_label('trail', $trail))));
    }
    $form_state['redirect'] = 'admin/content/trails';
  }
  else {
    drupal_set_message(t('There was an error during saving trail to the database. If the issue persists, please contact the site administrator'), 'error');
  }
}
