<?php
/**
 * Returns HTML for a simple table.
 */
function theme_simple($vars) {
  $form = $vars['form'];
  $rows = array();
  foreach (element_children($form) as $id) {
    if (isset($form[$id])) {
      $rows[] = array(
        'data' => array(
          drupal_render($form[$id]['act']),
          drupal_render($form[$id]['tech']),
          drupal_render($form[$id]['inventory']),
          drupal_render($form[$id]['status']),
          //drupal_render($form[$id]['customer']),
        ),
        'class' => array(),
      );
    }
  }
 
  $output = theme('table', array(
    'header' => $form['#header'],
    'rows'  => $rows,
    'empty' => t('На даний момент Вашої техніки в ремонті немає', array()),
  ));
 
  $output .= drupal_render_children($form);
  return $output;
}