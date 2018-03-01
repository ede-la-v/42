<?php

	$pseudo = htmlspecialchars($_GET["log"]);
	$pass = htmlspecialchars($_POST["pass"]);
	$vpass = htmlspecialchars($_POST["vpass"]);

	if ($pass != $vpass)
		header("Location: /index.php?error=pass1");
	else if (!preg_match('/.{8,20}/', $pass))
		header("Location: /index.php?error=pass2");
	else if (!preg_match('/[A-Z]+/', $pass))
		header("Location: /index.php?error=pass3");
	else if (!preg_match('/[0-9]+/', $pass))
		header("Location: /index.php?error=pass4");
	else
	{
		$pass = hash("whirlpool", $pass);
		Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
		Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/change_pass.php');
		header("Location: /index.php?change=1");
	}

	?>
