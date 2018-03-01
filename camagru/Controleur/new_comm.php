<?php
session_start();
if ($_SESSION["id"])
{
	Include_once($_SERVER['DOCUMENT_ROOT'].'/ConnexionBase.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/put_comm.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/get_user_comm.php');
	Include_once($_SERVER['DOCUMENT_ROOT'].'/Modele/get_user_by_id.php');
	if ($user[6])
	{
		$headers = "From: inscription@localhost.com\r\n";
		$headers .= "Reply-To: inscription@localhost.com\r\n";
		$headers .= "MIME-Version: 1.0\r\n";
		$headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";
		$message = "<!DOCTYPE html>
			<html>
			<body>
			<img src='http://localhost:8080/images/".$_POST["img"].".png' />
			<p>Votre photo a recu un commentaire de ".$user_comm[1].": ".$_POST["comm"]."</p>
			<hr>
			<p>Ceci est un mail automatique, Merci de ne pas y répondre.</p>
			</body>
			</html>";
mail($user[3], "Nouveau commentaire", $message, $headers);
	}
echo "saluti";
}
else
{
	http_response_code(400);
	echo "Veuillez vous connecter pour realiser cette action";
}


?>
