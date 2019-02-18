<?php

$db_host = "localhost";
$db_username = "root";
$db_pass = "CP2014";
$db_name = "gamesreview_db";

// connects to mysql server using the following : (host ,username , password)
// if no connect or incorrect details then the php script will die displaying the message Could not connect to MySQL
@mysql_connect("$db_host","$db_username","$db_pass") or die ("Could not connect to MySQL");


// connect to the correct database using the database name assigned
// if no databasse of that name is found the php script dies and displays the message no database
@mysql_select_db("$db_name") or die ("No database");

?>