<?php
// variable are equal to the input values, input by the user on the webmaster.html page
$master = $_GET['uName'];
$pass = $_GET['password'];
 // connects to the database through the included php page
 include 'mysql_connect.php';
// result equals all the results from the webmaster table
 $result = mysql_query("SELECT * FROM webmaster");
   // while the result is greater than 0 then proceed
   while($row = mysql_fetch_array($result)){

    if($master == $row['master'] && $pass == $row['password']){
      // when the if statement is true then the html page will be loaded onto the screen
      header('Location: ..\addReview.html');
    }

   }
   // if the page does not change then the following echos will be displayed as an error within the
   // webmaster username and/or password were incorrect
echo "<h1>you have entered an incorrect username and/or password</h1>";
echo "</br>";
echo "<h1>please try again or leave this section if you do not have the permission to gain access.</h1>";
echo "<br>";
echo "<table id='errorTable'><tr><td>";
echo "<form action='..\index.html'>";
echo "<input type='submit' value='Back'>";
echo "</form>";
echo "</td><td>";
echo "<form action='..\webmaster.html'>";
echo "<input type='submit' value='Try Again'>";
echo "</form>";
echo "</td></tr></table>";

?>