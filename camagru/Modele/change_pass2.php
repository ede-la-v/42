<?php
		$req = $bdd->prepare('
		UPDATE users 
		SET pass = :pass
		WHERE id = :pseudo');
		$req->execute(array('pass' => $pass, 'pseudo' => $_SESSION["id"]));

	
	
	?>
