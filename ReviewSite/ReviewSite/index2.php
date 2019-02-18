
<html>
<head>
    <title></title>
    <link rel="stylesheet" href="review.css">
    <script src="http://code.jquery.com/jquery-1.6.4.min.js"></script>
    <script src="search.js"></script>
</head>
<body background-color="#dddddd">
  <table id="headerTable">
      <tr>
          <td>
             <p>Section 1</p>
             <p>Header/Logo</p>
          </td>
      </tr>
      <tr>
          <td>
              <!-- the following buttons are used to guide the user through the website-->
              <table id="buttonsTable">
                  <tr>
                      <td>
                          <!--This form is used to allow the user to refresh the page, -->
                          <!-- using the form to create an action-->
<!--                          <form action="index.html">
                          <input id="home" type="submit" value="Home">
                          </form> -->
                          <button onclick="load('reviewsDiv2','homePage.html');">Home</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/3DS.php');">3DS</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/mac.php');">Mac</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/pc.php');">PC</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/ps3.php');">Playstation 3</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/ps4.php');">Playstation 4</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/psVita.php');">Playstation Vita</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/tablet.php');">Tablet</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/wii.php');">Wii</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/wiiU.php');">Wii U</button>
                      </td>
                      <td >
                          <button onclick="load('reviewsDiv2','php/xbox360.php');">XBox 360</button>
                      </td>
                      <td>
                          <button onclick="load('reviewsDiv2','php/xboxOne.php');">XBox One</button>
                      </td>
                  </tr>
              </table>
          </td>
      </tr>
  </table>
  <!-- this table holds the form for the user search facility using the form tags-->
  <!-- this allows for a fast and quick response from the database to gain the appropriate output-->
  <table id="searchTable">
      <tr>
          <td>
          <div id="test1"> </div>
              <!--the form on clickiing the submit button takes the user to the index2.php page-->
              <form  action="index2.php" method="get">
                  <h2>Customise your search</h2>
                  <b>Platform:</b>
                  <!-- uPlatform takes in the user choice of platform for searching-->
                  <select name="uPlatform">
                      <option value="ThreeDS">3DS</option>
                      <option value="Mac">Mac</option>
                      <option value="PC">PC</option>
                      <option value="PS3">Playstaytion 3</option>
                      <option value="PS4">Playstaytion 4</option>
                      <option value="PS Vita">PS Vita</option>
                      <option value="Tablets">Tablet</option>
                      <option value="Wii">Wii</option>
                      <option value="Wii U">Wii U</option>
                      <option value="XBox 360">XBox 360</option>
                      <option value="XBox One">XBox One</option>
                  </select>
                  <!-- uAge takes in the user age for searching-->
                  <b>Age:</b>
                  <select name="uAge">
                      <option value="3">3</option>
                      <option value="4">4</option>
                      <option value="5">5</option>
                      <option value="6">6</option>
                      <option value="7">7</option>
                      <option value="8">8</option>
                      <option value="9">9</option>
                      <option value="10">10</option>
                      <option value="11">11</option>
                      <option value="12">12</option>
                      <option value="13">13</option>
                      <option value="14">14</option>
                      <option value="15">15</option>
                      <option value="16">16</option>
                      <option value="17">17</option>
                      <option value="18">18 +</option>
                  </select>
                  <br>
                  <b>Genre</b>
                  <select name="uGenre">
                      <option value="">Select</option>
                      <option value="Action">Action</option>
                      <option value="Adventure">Adventure</option>
                      <option value="First Person Shooter">First Person Shooter</option>
                      <option value="Nonlinear">Nonlinear</option>
                      <option value="Party">Party</option>
                      <option value="Platform">Platform</option>
                      <option value="Puzzle">Puzzle</option>
                      <option value="Real Time Strategy">Real Time Strategy</option>
                      <option value="Role Playing Game">Role Playing Game</option>
                      <option value="Side Scroller">Side Scroller</option>
                      <option value="Simulation">Simulation</option>
                      <option value="Strategy">Strategy</option>
                      <option value="Survival Horror">Survival Horror</option>
                  </select>
                  <br>
                  <!-- uRating take in the users choice of ratings they wish to see-->
                  <b>Rating:</b>
                  <select name="uRating">
                      <option value="">Select</option>
                      <option value="0">0</option>
                      <option value="1">1</option>
                      <option value="2">2</option>
                      <option value="3">3</option>
                      <option value="4">4</option>
                      <option value="5">5</option>
                  </select>

                  <!-- uCoOp take in the users choice of co-operative they wish to see-->
                  <b>Co-Operative Play:</b>
                  <select name="uCoOp">
                      <option value="">Select</option>
                      <option value="Yes">Yes</option>
                      <option value="No">No</option>
                  </select>
                  <br>
                  <!-- uTypeOP take in the users choice of online or offline they wish to see-->
                  <b>Online:</b>
                  <select name="uTypeOP">
                     <option value="">Select</option>
                     <option value="Both">Online and Offline</option>
                     <option value="Online Only">Online Only</option>
                     <option value="Offline Only">Offline Only</option>
                  </select>
                  <br>
                  <!--the submit button sends the user input to the corresponding action -->
                  <!-- and method at the start of the form tag-->
                  <input id="search" type="submit" value="Search">
              </form>
          </td>
      </tr>
      <tr>
        <td>
           <table id="adverts1">
              <tr>
                 <td>
                   <h3>Advertising space1</h3>
                 </td>
              </tr>
           </table>
        </td>
      </tr>
      <tr>
        <td>
           <table id="adverts2">
              <tr>
                 <td>
                    <h3>Advertising space1</h3>
                 </td>
              </tr>
           </table>
        </td>
      </tr>
  </table>
  <!-- this table holds the main div were all the information will be displayed from the mysql query's set by  -->
  <!-- the buttons and the actions on the forms-->
  <table id="reviewList">
      <tr>
          <td>

              <div  id="reviewsDiv2" style="overflow: scroll; height:610px">
                <?php

                  // include calls and executes the php script before continuing on this page
                  // mysql_connect.php connects to the server ad database required
                  include 'php/searchDb.php';

                 ?>
              </div>
          </td>
      </tr>
  </table>
  <table id="footer">
        <tr>
            <td>
              <!-- the footer table holds all the legaal documentation and disclaimer to help the user,-->
              <!--in their use of the website-->
              <table id="footerTable">
                  <tr height="25%">
                      <td>
                          <!--the following a href take the user to the correct html page-->
                          <a href="#" onclick="load('reviewsDiv2','webmaster.html');">Webmaster</a>
                      </td>
                      <td>
                          <a href="#" onclick="load('reviewsDiv2','tAndC.html');">Terms and Conditions</a>
                      </td>
                      <td>
                          <a href="#" onclick="load('reviewsDiv2','contactUs.html');">Contact Us</a>
                      </td>
                      <td>
                          <a href="#" onclick="load('reviewsDiv2','help.html');">Help</a>
                      </td>
                  </tr>
              </table>
            </td>
        </tr>
    </table>

</body>
</html>