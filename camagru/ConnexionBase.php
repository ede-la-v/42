<?php
include($_SERVER['DOCUMENT_ROOT']."/config/database.php");
	
	try
{
	$bdd = new PDO('mysql:host=' . $mysql . ';dbname=' . $dbname, $dbuser, $mdp);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo 'Connection failed: ' . $e->getMessage();
}
?>
