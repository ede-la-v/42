<?php
session_start();
$pass = htmlspecialchars($_POST["pass"]);
$pass = hash("whirlpool", $pass);
	Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/Verifpass.php');
			header("Location: /index.php?change=4");
	if (!$resultat2)
		header("Location: /Vue/change_user.php?error=pass1");
	else
	{
		if ($_POST["mail"])
		{
			$email = htmlspecialchars($_POST["mail"]);
			if (!preg_match('/^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\.[a-zA-Z0-9._-]+$/', $email))
				header("Location: /Vue/change_user.php?error=mail1");
			else
			{
				Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/change_mail.php');
				header("Location: /index.php?change=1");
			}
		}
		if ($_POST["pseudo"])
		{
			Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/Verifpseudo_new.php');
			$pseudo = htmlspecialchars($_POST["pseudo"]);
			if (!preg_match('/.{6,}/', $pseudo))
				header("Location: /Vue/change_user.php?error=pseudo2");
			else if ($resultat)
				header("Location: /Vue/change_user.php?error=pseudo1");
			else
			{
				Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/change_login.php');
				header("Location: /index.php?change=2");
			}
		}
		if ($_POST["npass"])
		{
			$pass = htmlspecialchars($_POST["npass"]);
			if (!preg_match('/.{8,20}/', $pass))
				header("Location: /Vue/change_user.php?error=pass2");
			else if (!preg_match('/[A-Z]+/', $pass))
				header("Location: /Vue/change_user.php?error=pass3");
			else if (!preg_match('/[0-9]+/', $pass))
				header("Location: /Vue/change_user.php?error=pass4");
			else
			{
				$pass = hash("whirlpool", $pass);
				Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/change_pass2.php');
				header("Location: /index.php?change=3");
			}
		}
		if ($_POST["mess"])
		{	
			$bool = 1;
			Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/change_mess.php');
		}
		else
		{
			$bool = 0;
			Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/change_mess.php');
		}
	}
 
 	?>
