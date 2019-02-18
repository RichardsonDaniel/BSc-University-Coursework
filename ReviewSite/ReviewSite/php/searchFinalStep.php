<?php

                       // if ratings is true then step in
                          if($uCoOp == $row['coOp'] ){
                             // if CoOp is true then step in
                             if($uTypeOP == $row['online'] ){
                                // if online is true then step in and execute the following code to
                                //display the result in the index2.php
                                // and the $display is set to 1
                                // echo "age, platform, rating, coOp and typeOP true";
                                $displayed = "1";
                                include 'table.php';
                             }
                             elseif($uTypeOP == ""){
                                 // if online is empty then step in and execute the following code to
                                 //display the result in the index2.php to the point of CoOp
                                 // and the $display is set to 1
                                 // echo "age, platform, rating and coOp true and typeOP empty ";
                                 $displayed = "1";
                                 include 'table.php';
                             }

                          }
                          elseif($uCoOp == ""){
                             // if CoOp is empty then step in and execute the following code
                             if($uTypeOP == $row['online'] ){
                                 // if online is true then step in and execute the following code to
                                 //display the result in the index2.php to the point of online
                                 // and the $display is set to 1
                                 // echo "age, platform, rating true and coOp empty and typeOP true";
                                 $displayed = "1";
                                 include 'table.php';
                             }
                             elseif($uTypeOP == ""){
                                  // if CoOp is empty then step in and execute the following code to
                                  //display the result in the index2.php to the point of rating
                                  // and the $display is set to 1
                                  // echo "age, platform, rating  true and coOp and typeOP empty ";
                                  $displayed = "1";
                                  include 'table.php';
                             }

                          }


?>