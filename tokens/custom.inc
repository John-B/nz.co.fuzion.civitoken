<?php
/**
 * Created by: John_B
 * Date: 15/11/2021
 *
 * The purpose of this token is to get the raw value, rather than the label, of custom tokens.
 */

/**
 * @param $token
 *
 * @return array
 */
function custom_civitoken_declare($token) {
  return [
    $token . '.raw' => $token . ' raw value',
  ];
}

/**
 * @param $cid
 * @param $value
 */
function custom_civitoken_get($cid, &$value) {
  try {
    $user = civicrm_api3('contact', 'getsingle', ['contact_id' => $cid]);
    $value[$token . '.raw'] = $contact[$token];
  }
  catch (CiviCRM_API3_Exception $e) {
    $value[$token . '.raw'] = '';
  }


}
