<?php

	$pseudo = htmlspecialchars($_POST["pseudo"]);
	$pass = htmlspecialchars($_POST["pass"]);
	$vpass = htmlspecialchars($_POST["vpass"]);
	$email = htmlspecialchars($_POST["email"]);

	Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/verifpseudo_ins.php');

	if ($pass != $vpass)
		header("Location: /Vue/Inscription.php?error=pass1");
	else if (!preg_match('/^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\.[a-zA-Z0-9._-]+$/', $email))
		//echo $email;
		header("Location: /Vue/Inscription.php?error=mail1");
	else if ($resultat)
		header("Location: /Vue/Inscription.php?error=pseudo1");
	else if (!preg_match('/.{8,20}/', $pass))
		header("Location: /Vue/Inscription.php?error=pass2");
	else if (!preg_match('/[A-Z]+/', $pass))
		header("Location: /Vue/Inscription.php?error=pass3");
	else if (!preg_match('/[0-9]+/', $pass))
		header("Location: /Vue/Inscription.php?error=pass4");
	else if (!preg_match('/.{6,20}/', $pseudo))
		header("Location: /Vue/Inscription.php?error=pseudo2");
	else
	{
		$cle = md5(microtime(TRUE)*100000);
		$pass = hash("whirlpool", $pass);
		Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/Inscriptionbase.php');
		$headers = "From: inscription@localhost.com\r\n";
		$headers .= "Reply-To: inscription@localhost.com\r\n";
		$headers .= "MIME-Version: 1.0\r\n";
	$headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";
		$message = "<!DOCTYPE html>Bienvenue sur Fotooos,
		<html><body>	 
			Pour activer votre compte, veuillez cliquer sur le lien ci dessous
			ou copier/coller dans votre navigateur internet.
			 
			<a href='http://localhost:8080/Controleur/activation.php?log=".urlencode($pseudo)."&cle=".urlencode($cle)."'>Validation</a><br />
 
		 
		<hr/>
		Ceci est un mail automatique, Merci de ne pas y répondre.
		<html><body>";	 
mail($email, "Activer votre compte", $message, $headers);
header("Location: /index.php?ins=1");
	}

	?>
