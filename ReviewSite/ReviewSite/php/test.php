<?php

 // include calls and executes the php script before continuing on this page
  // mysql_connect.php connects to the server ad database required
 include 'mysql_connect.php';
 // result contains all of the reviews that have 3ds as the platform reviewed on
 $result = mysql_query("SELECT * FROM reviews");
 //  echo "<h1>3DS Review</h1>";
// echo $result;
 // while their is results the table.php will generate a table with the content
   while($row = mysql_fetch_array($result)){

       echo json_encode($row);
   }
?>