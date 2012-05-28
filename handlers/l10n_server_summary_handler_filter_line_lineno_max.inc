<?php

/**
 * @file
 * Definition of l10n_server_summary_handler_filter_line_lineno_max.
 */

/**
 * Filter handler to get just one line per string.
 */

class l10n_server_summary_handler_filter_line_lineno_max extends views_handler_filter {
  function query() {
    $this->operator = 'IN';

    $this->ensure_my_table();
    $placeholder = !empty($this->definition['numeric']) ? '%d' : "'%s'";

    $select = db_select('l10n_server_line', 'l10n_server_line_INNER');
    $select->addExpression("MIN(l10n_server_line_INNER.lineno)");
    $select->where("l10n_server_line_INNER.sid = $this->table_alias.sid");
    $select->where("l10n_server_line_INNER.rid = $this->table_alias.rid");

    $where = (string) $select;
    $in = '(' . $where . ')';

    // We use array_values() because the checkboxes keep keys and that can cause
    // array addition problems.
    $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field " . $this->operator . $in);
  }

}
