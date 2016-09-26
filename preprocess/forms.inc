<?php
/**
 * @file forms.inc
 * Overrides for accessible form elements.
 */

/**
 * Implements template_preprocess_select().
 */
function closing_the_gaps_preprocess_select(&$variables) {
  _closing_the_gaps_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_checkboxes().
 */
function closing_the_gaps_preprocess_checkboxes(&$variables) {
  _closing_the_gaps_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_input().
 */
function closing_the_gaps_preprocess_input(&$variables) {
  _closing_the_gaps_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_radios().
 */
function closing_the_gaps_preprocess_radios(&$variables) {
  _closing_the_gaps_accessible_required_forms($variables);
}

/**
 * Implements template_preprocess_textarea().
 */
function closing_the_gaps_preprocess_textarea(&$variables) {
  _closing_the_gaps_accessible_required_forms($variables);
}

/**
 * Helper function to clean up required for accessibility.
 *
 * @param array $variables
 */
function _closing_the_gaps_accessible_required_forms(&$variables = []) {
  // Remove the HTML5 "required" attribute to correct NVDA performace.
  // http://usability.com.au/2013/05/accessible-forms-2-required-fields-and-extra-information
  if (isset($variables['attributes']['required'])) {
    unset($variables['attributes']['required']);
  }
}
