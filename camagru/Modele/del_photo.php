
	
	<?php
	
	$req1 = $bdd->prepare('DELETE FROM images WHERE id = :id');
	$req1->execute(array(
    'id' => $photo
    ));
		
	
	?>
