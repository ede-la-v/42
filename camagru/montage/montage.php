<?php
session_start();
if (!$_SESSION["id"])
	header("Location: /Vue/Connexion.php");
else
{
  Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
  Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/last_img_user.php');
  header("Cache-Control: no-cache, must-revalidate");
  header("Expires: Mon, 26 Jul 1997 05:00:00 GMT");
clearstatcache();
?>


<!DOCTYPE html>
<html>
<head>
	<title>Montage</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
	<link rel="stylesheet" type="text/css" href="montage.css">
	<script src="montage.js"></script>
</head>
<body>
<div class="container">
<?php include($_SERVER['DOCUMENT_ROOT']."/Vue/entete.php"); ?>
	<div class="row">
	<div class="col-lg-8 text-center">
    <fieldset  >
      <legend>Webcam</legend>
      <img id="chap" src="http://ekladata.com/-6PR_q9lfWwRV4FymruNhlQ1sUE.png" class="hide effet"></img>
      <img id="stache" src="http://www.wallquotes.com/sites/default/files/arts0508.png" class="hide effet"></img>
	  <video autoplay class="text-center"></video>
    </fieldset>
	<img class="hide" src="../images/tmp.png" id="phot" />
<form class="hide row text-center navbar-form navbar-center inline-form" enctype="multipart/form-data" action="/Controleur/check_photo.php" method="post">
<div class="input-group">
  <input type="hidden" name="MAX_FILE_SIZE" value="5000000" />
  <label for="userfile" >Utiliser cette photo :</label> <input  name="userfile" type="file" />
  <input type="submit" value="Envoyer le fichier" class='btn btn-primary btn-sm'/>
</div>
</form>	  <br />
<button class="hide btn btn-primary btn-sm" id="takephoto">Prendre une photo</button>
    <div  class="row">
    <div id="cache" class="hide col-lg-6 col-lg-offset-3 text-center">
      <img id="chap2" src="http://ekladata.com/-6PR_q9lfWwRV4FymruNhlQ1sUE.png" />
      <img id="stache2" src="http://www.wallquotes.com/sites/default/files/arts0508.png" class=" effet" />
      </div>

    </div>
</div>

    <div id="l_foto" class="col-lg-3 col-lg-offset-1 bg-info">
        <legend>Dernieres photos</legend>
        <?php 
        if (isset($resultat[0]["id"]))
        { 
        ?>
        <div class="row text-center">
          <img class="img-thumbnail" src="/images/<?php echo $resultat[0]["id"] ?>.png"   />
        </div>
        <?php 
        }
        if (isset($resultat[1]["id"]))
        { 
        ?>
        <div class="row text-center">
            <img class="img-thumbnail" src="/images/<?php echo $resultat[1]["id"] ?>.png"  />
        </div>
        <?php 
        }
        if (isset($resultat[2]["id"]))
        { 
        ?>
        <div class="row text-center">
            <img class="img-thumbnail" src="/images/<?php echo $resultat[2]["id"] ?>.png"   />
        </div>
        <?php 
        }
        if (isset($resultat[3]["id"]))
        { 
        ?>
        <div class="row text-center">
            <img class="img-thumbnail" class="" src="/images/<?php echo $resultat[3]["id"] ?>.png"   />
        </div>
        <?php } ?>
      </div><br />
      
</div>
  
  


    <canvas class="hide"></canvas>
  <?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/footer.php'); ?>

  </div>
</body>
</html>
<?php
}
?>
