<?php
	session_start();

$photo = htmlspecialchars($_GET["photo"]);
$page = htmlspecialchars($_GET["page"]);
Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/del_photo.php');
unlink("../images/".$photo.".png");

if ($page)
	header("Location: /Vue/photo_user.php?page=".$page);
else
	header("Location: /Vue/photo_user.php");

 	?>
