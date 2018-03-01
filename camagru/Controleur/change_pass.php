<?php
	session_start();

$login = htmlspecialchars($_POST["pseudo"]);
Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/get_user.php');
if ($user)
{
	$cle = md5(microtime(TRUE)*100000);
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/change_cle.php');
	$headers = "From: inscription@localhost.com\r\n";
	$headers .= "Reply-To: inscription@localhost.com\r\n";
	$headers .= "MIME-Version: 1.0\r\n";
	$headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";
	$message = "<!DOCTYPE html>Bonjour,

		Pour reinitialiser votre MDP, veuillez cliquer sur le lien ci dessous
		ou copier/coller dans votre navigateur internet.

		<a href='http://localhost:8080/Controleur/modif_pass.php?log=".urlencode($login)."&cle=".urlencode($cle)."'>Validation</a><br />


		---------------<br />
		Ceci est un mail automatique, Merci de ne pas y répondre.";
mail($user[3], "Changer votre MDP", $message, $headers);
header("Location: /index.php?mail=1");
}
else
	header("Location: /Vue/change_pass.php?error=log");



 	?>
