<?php
	
	$req = $bdd->prepare('SELECT id FROM users WHERE id = :id AND pass = :pass');
	$req->execute(array('id' => $_SESSION["id"], 'pass' => $pass));
	$resultat2 = $req->fetch();
	
	?>
