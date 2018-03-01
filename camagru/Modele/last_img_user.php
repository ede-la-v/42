
	
	<?php
	
	$req = $bdd->prepare('SELECT id FROM images WHERE id_membre = :user ORDER BY id DESC LIMIT 4');
	$req->execute(array('user' => $_SESSION["id"]));
	$resultat = $req->fetchAll();
	
	?>