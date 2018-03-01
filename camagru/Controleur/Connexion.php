<?php
	session_start();
	$pseudo = htmlspecialchars($_POST["pseudo"]);
	$pass = htmlspecialchars($_POST["pass"]);
	$pass = hash("whirlpool", $pass);

	Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/Verifpseudo.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/Veriflogpass.php');
	print_r($resultat2);
	
	if (!$resultat)
		header("Location: /Vue/Connexion.php?error=pseudo");
	else if (!$resultat2)
		header("Location: /Vue/Connexion.php?error=pass");
	else
	{
		$_SESSION["id"] = $resultat["id"];
		header("Location: /index.php?con=1");
	}

	?>
