<?php

  // include calls and executes the php script before continuing on this page
  // mysql_connect.php connects to the server ad database required
 include 'mysql_connect.php';
// variable are assigned the value from the user input on the search form onn index.html and index2.php
$uPlatform = $_GET['uPlatform'];
$uAge = $_GET['uAge'];
$uGenre = $_GET['uGenre'];
$uRating = $_GET['uRating'];
$uCoOp = $_GET['uCoOp'];
$uTypeOP = $_GET['uTypeOP'];

// internal variable
// $notdisplayed sets to 1 when through the while loop when there is no match found
$notDisplayed = "0";
// $displayed sets to 1 when a game review is found within the database
$displayed = "0";

// result takes all from the reviews table where the platform  = the same as the user input
 $result = mysql_query("SELECT * FROM reviews");
   echo "<h1>Custom Search Reviews</h1>";
   // while $row greater than 0 enter else exit
   while($row = mysql_fetch_array($result)){
     // searching for games that are available on the users console, no matter what console they have been
     //reviewed on

     // 3DS
     if($uPlatform == "ThreeDS"){

      if($row['threeDS'] == "3DS"){

        include 'search.php';
      }
     }
     // Mac
     if($uPlatform == "Mac"){

       if($row['mac'] == "Mac"){

          include 'search.php';
       }
     }
     // PC
     if($uPlatform == "PC"){

       if($row['pc'] == "PC"){

         include 'search.php';
       }
     }
     // playstation 3
     if($uPlatform == "PS3"){

       if($row['ps3'] == "PS3"){

         include 'search.php';
       }
     }
     // Playstation 4
     if($uPlatform == "PS4"){

       if($row['ps4'] == "PS4"){

         include 'search.php';
       }
     }
     // Playstaytion Vita
     if($uPlatform == "PS Vita"){

       if($row['psVita'] == "PS Vita"){

         include 'search.php';
       }
     }
     // Tablet
     if($uPlatform == "Tablets"){

       if($row['tablet'] == "Tablets"){

         include 'search.php';
       }
     }
     // Wii
     if($uPlatform == "Wii"){

       if($row['wii'] == "Wii"){

         include 'search.php';
       }
     }
     // Wii U
     if($uPlatform == "Wii U"){

       if($row['wiiU'] == "Wii U"){

         include 'search.php';
       }
     }
     // XBox 360
     if($uPlatform == "XBox 360"){

       if($row['xbox360'] == "XBox 360"){

         include 'search.php';
       }
     }
     // XBox One
     if($uPlatform == "XBox One"){

       if($row['xboxOne'] == "XBox One"){

         include 'search.php';
       }
     }
   }

if($notDisplayed == "1" and $displayed == "0"){
   echo "Sorry, we have no current game reviews for your console and/or your age";
}

?>