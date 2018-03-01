<?php
	
	$req = $bdd->prepare('SELECT id FROM users WHERE id = :pseudo');
	$req->execute(array('pseudo' => $_SESSION["id"]));
	$resultat = $req->fetch();
	
	?>
