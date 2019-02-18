/**
 * Created by Toshiba on 06/03/14.
 */







/*
function createTable(){

    if($uAge >= $row['age']){
        // user age is greater than or equal to database age and platform is same if is true
        if($uRating == $row['rating'] ){
            // if ratings is true then step in
            if($uCoOp == $row['coOp'] ){
                // if CoOp is true then step in
                if($uTypeOP == $row['online'] ){
                    // if online is true then step in and execute the following code to
                    //display the result in the index2.php
                    // and the $display is set to 1
                    echo "age, platform, rating, coOp and typeOP true";
                    $displayed = "1";
                    include 'table.php';
                }
                elseif($uTypeOP == ""){
                    // if online is empty then step in and execute the following code to
                    //display the result in the index2.php to the point of CoOp
                    // and the $display is set to 1
                    echo "age, platform, rating and coOp true and typeOP empty ";
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
                    echo "age, platform, rating true and coOp empty and typeOP true";
                    $displayed = "1";
                    include 'table.php';
                }
                elseif($uTypeOP == ""){
                    // if CoOp is empty then step in and execute the following code to
                    //display the result in the index2.php to the point of rating
                    // and the $display is set to 1
                    echo "age, platform, rating  true and coOp and typeOP empty ";
                    $displayed = "1";
                    include 'table.php';
                }
            }
        }
        elseif($uRating == ""){

            if($uCoOp == $row['coOp'] ){
                // if CoOp is true then step in and execute the following code

                if($uTypeOP == $row['online'] ){
                    // if online is true then step in and execute the following code to
                    //display the result in the index2.php to the point of online
                    // and the $display is set to 1
                    echo "age, platform, true and rating and coOp empty and typeOP true ";
                    $displayed = "1";
                    include 'table.php';
                }
                elseif($uTypeOP == ""){
                    // if online is empty then step in and execute the following code to
                    //display the result in the index2.php to the point of CoOp
                    // and the $display is set to 1
                    echo "age, platform, true and rating, coOp and typeOP  empty";
                    $displayed = "1";
                    include 'table.php';
                }
            }
            elseif($uCoOp == ""){
                // if CoOp is empty then step in and execute the following code to
                if($uTypeOP == $row['online'] ){
                    // if online is true then step in and execute the following code to
                    //display the result in the index2.php to the point of online
                    // and the $display is set to 1
                    echo "age, platform, true and rating empty and coOp true ";
                    $displayed = "1";
                    include 'table.php';
                }
                elseif($uTypeOP == ""){
                    // if online is empty then step in and execute the following code to
                    //display the result in the index2.php to the point of rating
                    // and the $display is set to 1
                    echo "age, platform, true and rating, coOp and typeOP empty";

                    $displayed = "1";
                    include 'table.php';
                }
            }
};
*/
function load(location, loadFile){
    //sets XMLHttp variable
    if(window.XMLHttpRequest){
        xmlhttp = new XMLHttpRequest();
    }else{
        xmlhttp = new ActiveXObject('Microsoft.XMLHTTP');
    }

    xmlhttp.onreadystatechange = function(){
        // checks for state chang if state change modify contents of the location
        if (xmlhttp.readyState==4 && xmlhttp.status==200){
            document.getElementById(location).innerHTML = xmlhttp.responseText;
        }
    }
    // gets the file  requested
    xmlhttp.open('GET', loadFile, true);
    // the send, sends the data
    xmlhttp.send();
};

window.onload = function(){
    //load('search', 'php/searchDB.php');
    load('reviewsDiv2','homePage.html');
    //xbox360click = document.getElementById("xbox360click");
    //xbox360click.onclick = load('test1','php/searchDB.php');
  //  getDatabase();
   // load('test2','load.php');

  //  search = document.getElementById('search');
  //  search.onclick = getDatabase("reviewsDiv");


};