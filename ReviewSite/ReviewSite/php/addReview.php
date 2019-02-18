<?php

// include calls and executes the php script before continuing on this page
// mysql_connect.php connects to the server ad database required
include 'mysql_connect.php';

// define_variables with teh $_Post values gained from the form on the addReviews.html page
$name = $_POST['name'];
$image = $_POST['imageLoc'];
$developer = $_POST['developer'];
$publisher = $_POST['publisher'];
$genre = $_POST['genre'];
$ps3 = $_POST['pS3'];
$ps4 = $_POST['pS4'];
$wii = $_POST['wii'];
$wiiU = $_POST['wiiU'];
$xbox360 = $_POST['xBox360'];
$xboxOne = $_POST['xBoxOne'];
$psVita = $_POST['pSVita'];
$threeDS = $_POST['3DS'];
$pc = $_POST['pc'];
$mac = $_POST['mac'];
$tablet = $_POST['tablets'];
$age = $_POST['age'];
$type = $_POST['typeOP'];
$coOp = $_POST['coOp'];
$formatHC = $_POST['formatHC'];
$formatD = $_POST['formatD'];
$formatWA = $_POST['formatWA'];
$platform = $_POST['platform'];
$single = $_POST['singleDescrip'];
$multi = $_POST['multiDescrip'];
$rating = $_POST['rating'];


 // insets the variable values in to the table with the corresponding table headers
 mysql_query("INSERT INTO reviews (`id`,`name`,`image`,`developer`,`publisher`,`genre`,`ps3`,`ps4`,`wii`,`wiiU`,`xbox360`,`xboxOne`,`psVita`,`threeDS`,`pc`,`mac`,`tablet`,`age`,`online`,`coOp`,`formatHC`,`formatD`,`formatWA`,`platform`,`singlePlayer`,`multiPlayer`,`rating`)
            VALUES (NULL,'$name','$image','$developer','$publisher','$genre','$ps3','$ps4','$wii','$wiiU','$xbox360',
            '$xboxOne','$psVita','$threeDS','$pc','$mac','$tablet','$age','$type','$coOp','$formatHC','$formatD',
            '$formatWA','$platform','$single','$multi','$rating')")
            or die (mysql_error());

 // location of file has .. as the targeted html document is a external file to the folder
 // were this file if held
 header('Location: ..\addReview.html');
?>