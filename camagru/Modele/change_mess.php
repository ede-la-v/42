<?php
	
		$req = $bdd->prepare('
		UPDATE users 
		SET message = :bool
		WHERE id = :id');
		$req->execute(array('bool' => $bool, 'id' => $_SESSION["id"]));

	
	
	?>
