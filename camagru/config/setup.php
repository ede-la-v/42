
	
	<?php
	include($_SERVER['DOCUMENT_ROOT']."/config/database.php");
	try
{
	$bdd = new PDO('mysql:host=' . $mysql, $dbuser, $mdp);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo 'Connection failed: ' . $e->getMessage();
}
	
	$req = $bdd->prepare('CREATE DATABASE camagru');
	$req->execute();
 	
	try
{
	$bdd = new PDO('mysql:host=' . $mysql . ';dbname=' . $dbname, $dbuser, $mdp);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo 'Connection failed: ' . $e->getMessage();
}
		
	$req2 = $bdd->prepare("CREATE TABLE users (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
login VARCHAR(30) NOT NULL,
pass VARCHAR(200) NOT NULL,
email VARCHAR(50) NOT NULL,
cle VARCHAR(32) NOT NULL,
valid INT DEFAULT 0,
message INT DEFAULT 1
)");
	$req2->execute();

	$req3 = $bdd->prepare("CREATE TABLE images (
id INT(10) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
id_membre INT(6) UNSIGNED NOT NULL, 
add_date datetime DEFAULT CURRENT_TIMESTAMP
)");
	$req3->execute();

	$req4 = $bdd->prepare("CREATE TABLE likes (
id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
id_photo INT(10) UNSIGNED NOT NULL, 
id_membre INT(6) UNSIGNED NOT NULL, 
add_date datetime DEFAULT CURRENT_TIMESTAMP
)");
	$req4->execute();

	$req5 = $bdd->prepare("CREATE TABLE commentaires (
id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
id_photo INT(10) UNSIGNED NOT NULL,
id_membre INT(6) UNSIGNED NOT NULL, 
comm VARCHAR(500) NOT NULL,
add_date datetime DEFAULT CURRENT_TIMESTAMP
)");
	$req5->execute();

 
header("Location: /");

	?>
