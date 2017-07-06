<?php

/**
 * Implements hook_sql_sync_sanitize().
 */
function smtp_drush_sql_sync_sanitize($site) {
  // List of smtp variables to delete from database.
  $smtp_variables = array(
    'smtp_default_provider',
    'smtp_host',
    'smtp_hostbackup',
    'smtp_on',
    'smtp_password',
    'smtp_providers',
    'smtp_reroute_address',
    'smtp_username',
  );

  // Deletes listed smtp variables and all selection criterias, because there 
  // will be no providers for them. Also clears all mail queues.
  $sql = "DELETE FROM variable WHERE name IN ('" . implode("','", $smtp_variables) . "');"
         . 'DELETE FROM smtp_selection_criteria;'
         . "DELETE FROM queue WHERE name IN ('smtp_send_queue', 'smtp_failure_queue');";
  drush_sql_register_post_sync_op('smtp_variables', dt('Remove sensitive SMTP data'), $sql);

  // As all providers will be deleted, restore the default mail system.
  $sql = "DELETE FROM variable WHERE name = 'mail_system';";
  drush_sql_register_post_sync_op('smtp_mail_system', dt('Restore default Mail System'), $sql);
}
