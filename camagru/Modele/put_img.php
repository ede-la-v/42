
	
	<?php
	
	$req1 = $bdd->prepare('INSERT INTO images(id_membre) VALUES(:id)');
	$req1->execute(array(
    'id' => $_SESSION["id"]));
		
	
	?>
