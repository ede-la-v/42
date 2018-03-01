<?php
	
	$req = $bdd->prepare('SELECT id FROM users WHERE login = :pseudo AND valid = 1');
	$req->execute(array('pseudo' => $pseudo));
	$resultat = $req->fetch();
	
	?>
