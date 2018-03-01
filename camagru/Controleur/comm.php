<?php
session_start();

Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/get_comm.php');

echo json_encode($resultat);


?>
