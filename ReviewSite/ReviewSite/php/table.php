<?php
// this table is the main table that hold all of the data
      // being output for each row
      echo "<table id='review' border='1'><tr><td>";

        // this table hold the game name, pegi rating and review rating
        echo "<table id='reviewTitle' width='100%'><tr><td>";
             // outputs the name to the user
             echo "<b>". $row['name'] ." </b>";
             // the switch checks to see if the entered age is the same as the case statements
             // when true then displays an image and exits case
             switch ($row['age']){
              case "3":
               // this line of code builds a source location for an image by adding
               // the information found in the row$['age'] to the predecessors
               // pegi/pegi then adds .png at the end, gaining the location of the image
               echo "<img id='pegi'  src='pegi/pegi". $row['age'] .".png' >";
               break;
              case "7":
               echo "<img id='pegi'  src='pegi/pegi". $row['age'] .".png' >";
               break;
              case "12":
               echo "<img id='pegi'  src='pegi/pegi". $row['age'] .".png' >";
               break;
              case "16":
               echo "<img id='pegi'  src='pegi/pegi". $row['age'] .".png' >";
               break;
              case "18":
               echo "<img id='pegi'  src='pegi/pegi". $row['age'] .".png' >";
               break;
              }
             echo "</td><td align='right'>";
             switch ($row['rating']){
               case "1":
                 // this line of code builds a source location for an image by adding
                 // the information found in the row$['age'] to the predecessors
                 // pegi/pegi then adds .png at the end, gaining the location of the image
                 echo "<img id='rating'  src='ratings/". $row['rating'] .".png' >";
                 break;
               case "2":
                 echo "<img id='rating'  src='ratings/". $row['rating'] .".png' >";
                 break;
               case "3":
                 echo "<img id='rating'  src='ratings/". $row['rating'] .".png' >";
                 break;
               case "4":
                 echo "<img id='rating'  src='ratings/". $row['rating'] .".png' >";
                 break;
               case "5":
                 echo "<img id='rating'  src='ratings/". $row['rating'] .".png' >";
                 break;
             }
        // closes reviewTitle table
        echo "</td></tr></table>";


        // this table holds all the standard game details i.e image, developer, genre etc.
        echo "<table id='gameDetails' width='100%'><tr><td>";

            // this table holds the image of the review game
            echo "<table id='imageTable' width='100%'><tr><td>";
              // this line of code builds a source location for an image by adding
              // the information found in the row$['age'] to the predecessors
              // reviewImages/ then adds .png at the end, gaining the location of the image
              echo "<img id='reviewImage' src='reviewImages/". $row['image'] ."'>";
            // closes imageTable
            echo "</td></tr></table>";

        echo "</td><td>";

            // this table hold the game info developer, genre, publisher etc.
            echo "<table id='gameInfo'><tr><td>";
              // displays developer
              echo "<h4>Developer : </h4><p>". $row['developer'];
             echo "</p></td></tr><tr><td>";
              // displays publisher
              echo "<h4>Publisher : </h4><p>". $row['publisher'];
             echo "</p></td></tr><tr><td>";
              // displays genre
              echo "<h4>Genre: </h4><p>". $row['genre'];
             echo "</p></td></tr><tr><td>";
              echo "<h4>Network : </h4><p>";
                // if check what online field holds if it is both then statement is true and executes
                // else it displays the content of $row['online']
                if ($row['online'] == "Both"){
                     echo "online and offline available";
                }
                else{
                     echo $row['online'];
                }
             echo "</p></td></tr><tr><td>";
                     echo "<h4>Co-Op : </h4><p>";
                     echo $row['coOp'];
             echo "</p></td></tr><tr><td>";
                     echo "<h4>Available Formats : </h4><p>";
                     // if checks if format is empty if it is not empty then displays content
                     // of $row['formatHC']
                      if($row['formatHC'] != ""){
                          echo  $row['formatHC'] .", ";
                      }
                      if($row['formatD'] != ""){
                          echo $row['formatD'] .", ";
                      }
                      if($row['formatWA'] != ""){
                          echo  $row['formatWA'];
                      }
            // closes gameInfo table
            echo "</p></td></tr></table>";
        // closes gamesDetails table
        echo "</td></tr></table>";

        echo "<hr>";

        // this table holds all the review information and available consoles
        echo "<table id='gameReview'><tr><td>";
            echo "<h4>Reviewed On: </h4><p> " . $row['platform'] ."</p>";
          echo "</td></tr><tr><td>";
            echo "<h4>Single Player :</h4>";
          echo "</td></tr><tr><td>";
            // displays the single player review
            echo "<p>". $row['singlePlayer'] ."</p>";
          echo "</td></tr><tr><td>";
            echo "<h4> Multi-Player : </h4>";
          echo "</td></tr><tr><td>";
            // displays the multiplayer review
            echo "<p>". $row['multiPlayer'] ."</p>";
          echo "</td></tr><tr><td>";
            // displays the available consoles the game is available on
            // by check each console field is not empty then display its content
            echo "<h4>Available on : </h4>";
          echo "</td></tr><tr><td><p>";
            // by creating these if statements allows for a list of the available consoles
            // the game is available on. if the field is empty then it is not added to the list
            if($row['ps3'] != ""){
               // displays field content with a comma and space afterwards
               // this means that any of the consoles can start the list and end it
               echo $row['ps3'] .", ";
            }
            if($row['ps4'] != ""){
               echo $row['ps4'] .", ";
            }
            if($row['wii'] != ""){
               echo $row['wii'] .", ";
            }
            if($row['wiiU'] != ""){
               echo $row['wiiU'] .", ";
            }
            if($row['xbox360'] != ""){
               echo $row['xbox360'] .", ";
            }
            if($row['xboxOne'] != ""){
               echo $row['xboxOne'] .", ";
            }
            if($row['psVita'] != ""){
               echo $row['psVita'] .", ";
            }
            if($row['threeDS'] != ""){
               echo $row['threeDS'] .", ";
            }
            if($row['pc'] != ""){
               echo $row['pc'] .", ";
            }
            if($row['mac'] != ""){
               echo $row['mac'] .", ";
            }
            if($row['tablet'] != ""){
               echo $row['tablet'] .", ";
            }
        // closes gameReview table
        echo "</p></td></tr></table>";
      // closes review table
      echo "</td></tr></table>";

    echo "<hr>";
?>